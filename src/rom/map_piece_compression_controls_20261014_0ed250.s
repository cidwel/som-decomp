.setcpu "65816"
.segment "CODE"
.org $D250
map_control_0ed250:
    .byte $E5 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
