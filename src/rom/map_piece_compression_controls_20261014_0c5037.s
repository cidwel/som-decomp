.setcpu "65816"
.segment "CODE"
.org $5037
map_control_0c5037:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
    .byte $CF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $3D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $75 ; row-distance/count
