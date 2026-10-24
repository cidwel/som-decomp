.setcpu "65816"
.segment "CODE"
.org $AD3A
map_control_0ead3a:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
    .byte $E5 ; previous-row copy count
