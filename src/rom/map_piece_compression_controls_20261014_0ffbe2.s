.setcpu "65816"
.segment "CODE"
.org $FBE2
map_control_0ffbe2:
    .byte $E1 ; previous-row copy count
