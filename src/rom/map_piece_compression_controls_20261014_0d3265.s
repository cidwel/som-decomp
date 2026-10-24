.setcpu "65816"
.segment "CODE"
.org $3265
map_control_0d3265:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
