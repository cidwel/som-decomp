.setcpu "65816"
.segment "CODE"
.org $7FC9
map_control_0f7fc9:
    .byte $EA ; backreference distance high bits
    .byte $89 ; distance low bit/count
