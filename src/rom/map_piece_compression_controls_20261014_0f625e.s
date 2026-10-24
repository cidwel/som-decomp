.setcpu "65816"
.segment "CODE"
.org $625E
map_control_0f625e:
    .byte $CF ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
