.setcpu "65816"
.segment "CODE"
.org $18C9
map_control_0e18c9:
    .byte $EB ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
