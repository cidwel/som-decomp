.setcpu "65816"
.segment "CODE"
.org $87DC
map_control_0f87dc:
    .byte $C2 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E3 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
