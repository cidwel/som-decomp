.setcpu "65816"
.segment "CODE"
.org $2BFE
map_control_0e2bfe:
    .byte $E5 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
