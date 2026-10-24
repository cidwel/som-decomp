.setcpu "65816"
.segment "CODE"
.org $11ED
map_control_0e11ed:
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $4F ; distance low bit/count
