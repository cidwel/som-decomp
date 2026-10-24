.setcpu "65816"
.segment "CODE"
.org $7E6D
map_control_0d7e6d:
    .byte $E2 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
