.setcpu "65816"
.segment "CODE"
.org $52DA
map_control_0d52da:
    .byte $EB ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
