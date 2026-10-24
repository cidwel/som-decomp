.setcpu "65816"
.segment "CODE"
.org $CF30
map_control_0dcf30:
    .byte $E1 ; previous-row copy count
