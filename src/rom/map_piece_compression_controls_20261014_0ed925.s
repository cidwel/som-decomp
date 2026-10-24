.setcpu "65816"
.segment "CODE"
.org $D925
map_control_0ed925:
    .byte $D7 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
