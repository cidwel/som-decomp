.setcpu "65816"
.segment "CODE"
.org $41BF
map_control_0e41bf:
    .byte $E4 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
