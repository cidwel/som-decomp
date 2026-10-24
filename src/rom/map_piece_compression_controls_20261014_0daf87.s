.setcpu "65816"
.segment "CODE"
.org $AF87
map_control_0daf87:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
