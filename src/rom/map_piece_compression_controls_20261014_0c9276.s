.setcpu "65816"
.segment "CODE"
.org $9276
map_control_0c9276:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
