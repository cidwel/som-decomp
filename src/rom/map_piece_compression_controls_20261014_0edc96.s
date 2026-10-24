.setcpu "65816"
.segment "CODE"
.org $DC96
map_control_0edc96:
    .byte $D2 ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
