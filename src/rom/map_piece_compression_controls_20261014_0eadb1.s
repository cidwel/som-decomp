.setcpu "65816"
.segment "CODE"
.org $ADB1
map_control_0eadb1:
    .byte $E1 ; previous-row copy count
