.setcpu "65816"
.segment "CODE"
.org $3FAC
map_control_0c3fac:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
