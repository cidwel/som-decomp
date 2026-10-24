.setcpu "65816"
.segment "CODE"
.org $034C
map_control_0f034c:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
