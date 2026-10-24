.setcpu "65816"
.segment "CODE"
.org $E2E7
map_control_0de2e7:
    .byte $E2 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C9 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $D2 ; same-value copy count/distance
    .byte $D9 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
