.setcpu "65816"
.segment "CODE"
.org $C8FC
map_control_0fc8fc:
    .byte $E1 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $95 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
