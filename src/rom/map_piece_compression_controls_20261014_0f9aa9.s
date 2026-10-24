.setcpu "65816"
.segment "CODE"
.org $9AA9
map_control_0f9aa9:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
