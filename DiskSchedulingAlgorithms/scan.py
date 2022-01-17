number_of_tracks = int(input("Enter Number Of Tracks: "))
head = int(input("Enter current head: "))
direction = input("Enter the direction: [Right : r] or [Left : l] : ")
seek_time = 0
disk_size = 200
i = 0
route = []
queue_left = []
queue_right = []

print("Please start entering the request queue: ")
while(i < number_of_tracks):
    x = int(input(f"Track [{i}] = "))
    if(x < head):
        queue_left.append(x)
    else:
        queue_right.append(x)
    i += 1

queue_left.sort()
queue_right.sort()

if direction == "r":
    route.append(head)
    for i in range(0, len(queue_right)):
        seek_time += abs(head-queue_right[i])
        head = queue_right[i]
        route.append(head)
    seek_time += abs(head-(disk_size-1))
    head = disk_size - 1
    queue_left.reverse()
    for i in range(0, len(queue_left)):
        seek_time += abs(head-queue_left[i])
        head = queue_left[i]
        route.append(head)

elif direction == "l":
    route.append(head)
    queue_left.reverse()
    for i in range(0, len(queue_left)):
        seek_time += abs(head-queue_left[i])
        head = queue_left[i]
        route.append(head)
    seek_time += abs(head)
    head = 0
    for i in range(0, len(queue_right)):
        seek_time += abs(head-queue_right[i])
        head = queue_right[i]
        route.append(head)


print("Start --> ", end="")
for track in route:
    print(track, end=" --> ")
print(" End")
print(f"Seek time = {seek_time}")
print(f"Average Seek Time: {float(seek_time)/float(number_of_tracks)}")

