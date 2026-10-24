.setcpu "65816"
.segment "CODE"
.org $02EB
map_control_0f02eb:
    .byte $CA ; same-value copy count/distance
    .byte $D9 ; same-value copy count/distance
    .byte $D1 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $05 ; distance low bit/count
