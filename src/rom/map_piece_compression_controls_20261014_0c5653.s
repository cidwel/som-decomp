.setcpu "65816"
.segment "CODE"
.org $5653
map_control_0c5653:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
