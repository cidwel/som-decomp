.setcpu "65816"
.segment "CODE"
.org $929B
map_control_0c929b:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
