.setcpu "65816"
.segment "CODE"
.org $7801
map_control_0f7801:
    .byte $D1 ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
