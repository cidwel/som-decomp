.setcpu "65816"
.segment "CODE"
.org $9707
map_control_0f9707:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
