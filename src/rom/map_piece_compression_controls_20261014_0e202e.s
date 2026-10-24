.setcpu "65816"
.segment "CODE"
.org $202E
map_control_0e202e:
    .byte $E2 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
