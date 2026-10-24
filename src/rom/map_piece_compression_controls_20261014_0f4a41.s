.setcpu "65816"
.segment "CODE"
.org $4A41
map_control_0f4a41:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
