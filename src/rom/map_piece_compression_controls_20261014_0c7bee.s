.setcpu "65816"
.segment "CODE"
.org $7BEE
map_control_0c7bee:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $45 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
