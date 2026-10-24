.setcpu "65816"
.segment "CODE"
.org $9F89
map_control_0e9f89:
    .byte $E1 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
