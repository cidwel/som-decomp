.setcpu "65816"
.segment "CODE"
.org $7E87
map_control_0c7e87:
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
