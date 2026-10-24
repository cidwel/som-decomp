.setcpu "65816"
.segment "CODE"
.org $3278
map_control_0f3278:
    .byte $F1 ; progressive-copy count
    .byte $C9 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
