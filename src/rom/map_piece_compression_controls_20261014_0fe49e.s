.setcpu "65816"
.segment "CODE"
.org $E49E
map_control_0fe49e:
    .byte $C1 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
