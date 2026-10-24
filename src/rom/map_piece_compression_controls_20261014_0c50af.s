.setcpu "65816"
.segment "CODE"
.org $50AF
map_control_0c50af:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $D5 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
