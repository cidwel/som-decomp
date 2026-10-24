.setcpu "65816"
.segment "CODE"
.org $5E09
map_control_0d5e09:
    .byte $E0 ; previous-row copy escape
    .byte $A8 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
