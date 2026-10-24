.setcpu "65816"
.segment "CODE"
.org $9DC0
map_control_0f9dc0:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
