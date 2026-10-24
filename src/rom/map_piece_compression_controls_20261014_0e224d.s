.setcpu "65816"
.segment "CODE"
.org $224D
map_control_0e224d:
    .byte $E3 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
