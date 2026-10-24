.setcpu "65816"
.segment "CODE"
.org $9424
map_control_0f9424:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
