.setcpu "65816"
.segment "CODE"
.org $DC0F
map_control_0fdc0f:
    .byte $CF ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $21 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $31 ; row-distance/count
