.setcpu "65816"
.segment "CODE"
.org $D389
map_control_0ed389:
    .byte $DC ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E4 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $09 ; distance low bit/count
