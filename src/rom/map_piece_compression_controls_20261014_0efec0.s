.setcpu "65816"
.segment "CODE"
.org $FEC0
map_control_0efec0:
    .byte $E1 ; previous-row copy count
