.setcpu "65816"
.segment "CODE"
.org $5453
map_control_0c5453:
    .byte $EE ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
