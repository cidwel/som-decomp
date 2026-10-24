.setcpu "65816"
.segment "CODE"
.org $5750
map_control_0c5750:
    .byte $C1 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
