.setcpu "65816"
.segment "CODE"
.org $18FC
map_control_0c18fc:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
