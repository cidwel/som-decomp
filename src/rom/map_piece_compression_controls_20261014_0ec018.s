.setcpu "65816"
.segment "CODE"
.org $C018
map_control_0ec018:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
