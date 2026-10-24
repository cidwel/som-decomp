.setcpu "65816"
.segment "CODE"
.org $2BFE
map_control_0d2bfe:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
