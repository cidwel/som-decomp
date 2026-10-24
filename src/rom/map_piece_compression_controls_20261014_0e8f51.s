.setcpu "65816"
.segment "CODE"
.org $8F51
map_control_0e8f51:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
