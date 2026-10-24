.setcpu "65816"
.segment "CODE"
.org $D509
map_control_0fd509:
    .byte $E1 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
