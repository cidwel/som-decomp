.setcpu "65816"
.segment "CODE"
.org $5BBC
map_control_0c5bbc:
    .byte $C4 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $86 ; distance low bit/count
