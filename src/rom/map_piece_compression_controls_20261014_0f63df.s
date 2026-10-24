.setcpu "65816"
.segment "CODE"
.org $63DF
map_control_0f63df:
    .byte $E3 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
