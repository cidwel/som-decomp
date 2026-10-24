.setcpu "65816"
.segment "CODE"
.org $8FC5
map_control_0e8fc5:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
