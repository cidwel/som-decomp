.setcpu "65816"
.segment "CODE"
.org $4FE9
map_control_0f4fe9:
    .byte $E1 ; previous-row copy count
    .byte $D1 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
