.setcpu "65816"
.segment "CODE"
.org $61B8
map_control_0d61b8:
    .byte $C1 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
